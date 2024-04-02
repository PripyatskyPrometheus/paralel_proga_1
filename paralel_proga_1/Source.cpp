#include<iostream>
#include<fstream>
#include<random>
#include <chrono>
#include <time.h>
#include <omp.h>
#pragma omp parallel for

using namespace std;

class MULTI_MATRIX {
private:
	int size;
	int** matrix_1;
	int** matrix_2;
	int** result_matrix;
	string file_matrix_1 = "matrix_1.txt";
	string file_matrix_2 = "matrix_2.txt";
	string file_result_matrix = "result_matrix.txt";

	int** creat_matrix(int size) {
		int** matrix = new int*[size];
		for (int i = 0; i < size; i++) {
			matrix[i] = new int[size];
		}
		return matrix;
	}

    void random_matrix_file(int** matrix, const string& filename) {
        srand(time(NULL));
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                (matrix)[i][j] = rand() % 256;
            }
        }
        ofstream file(filename);
        file << size << endl;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                file << (matrix)[i][j] << " ";
            }
            file << endl;
        }
        file.close();
    }

    void write_file(int** matrix, const string& filename) {
        ofstream file(filename);
        file << size << endl;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                file << matrix[i][j] << " ";
            }
            file << endl;
        }
        file.close();
    }

public:
	MULTI_MATRIX(int N) {
		size = N;
		matrix_1 = creat_matrix(size);
		matrix_2 = creat_matrix(size);
		result_matrix = creat_matrix(size);
	}

    void generate_matrix() {
        random_matrix_file(matrix_1, file_matrix_1);
        random_matrix_file(matrix_2, file_matrix_2);
    }

    void multiply() { 
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result_matrix[i][j] = 0;
                for (int q = 0; q < size; q++) {
                    result_matrix[i][j] += matrix_1[i][q] * matrix_2[q][j];
                }
            }
        }
        write_file(result_matrix, file_result_matrix);
    }

    void clean(int** matrix) {
        for (int i = 0; i < size; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    ~MULTI_MATRIX() {
        clean(matrix_1);
        clean(matrix_2);
        clean(result_matrix);
    }
};

void write_time_file(long long time, const string& filename) {
    ofstream file(filename, ios::app);
    file << time << endl;
    file.close();
}

void write_task_file(int size, long long task_size, const string& filename) {
    ofstream file(filename, ios::app);
    file << size << endl << task_size << endl;
    file.close();
}

int main() {
	setlocale(LC_ALL, "Russian");
    int size_0 = 100;
    string file_name = "stats.txt";
    while (size_0 <= 1000) {
        long long task = static_cast<long long>(size_0) * static_cast<long long>(size_0) * static_cast<long long>(size_0);
        write_task_file(size_0, task, file_name);
        for (int i = 0; i < 10; i++) {
            MULTI_MATRIX matrix = MULTI_MATRIX(size_0);
            matrix.generate_matrix();
            auto start = chrono::steady_clock::now();
            matrix.multiply();
            auto end = chrono::steady_clock::now();
            auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
            write_time_file(duration.count(), file_name);
        }
        size_0 += 100;
    }
	return 0;
}