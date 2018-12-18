
#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

//static double stringToNumber(char *string);

static vector<vector<double>> parseProbabilities(char *argv[], int *argID, int N, int M);

static vector<double> parseNumbersD(char *argv[], int *argID, int size);

static vector<int> parseNumbersI(char *argv[], int *argID, int size);

int main(int argc, char *argv[]) {
    if (argc < 4)
        return 1;

    int argID = 1;

    //FILL T, N, M:
    int T = std::stoi(argv[argID++]);
    int N = std::stoi(argv[argID++]);
    int M = std::stoi(argv[argID++]);

    //FILL PROBABILITIES:
    vector<vector<double> > probabilities = parseProbabilities(argv, &argID, N, M);

    //FILL INPUT CHANNEL POISSON PARAMETERS:
    vector<double> lambdas = parseNumbersD(argv, &argID, N);

    //FILL QUEUE SIZES:
    vector<int> queueSizes = parseNumbersI(argv, &argID, M);

    //FILL OUTPUT CHANNEL POISSON PARAMETERS:
    vector<double> mus = parseNumbersD(argv, &argID, M);


}


vector<vector<double> > parseProbabilities(char *argv[], int *argID, int N, int M) {
    vector<vector<double> > probabilities;
    for (int n = 0; n < N; n++) {
        vector<double> channelProbabilities = parseNumbersD(argv, argID, M);
        probabilities.push_back(channelProbabilities);
    }
    return probabilities;
}


vector<double> parseNumbersD(char *argv[], int *argID, int size) {
    vector<double> output;
    for (int n = 0; n < size; n++) {
        string str(argv[(*argID)++]);
        double element = std::stod(str);
        output.push_back(element);
    }
    return output;
}

vector<int> parseNumbersI(char *argv[], int *argID, int size) {
    vector<int> output;
    for (int n = 0; n < size; n++) {
        string str(argv[(*argID)++]);
        int element = std::stoi(str);
        output.push_back(element);
    }
    return output;
}

//CODE THAT DEBUGS CORRECT FILLING
//cout << T << " " << N << " " << M << endl;
//for (int i = 0; i < N; i++) {
//for (int j = 0; j < M; j++) {
//cout << probabilities[i][j];
//cout << " ";
//}
//cout << endl;
//}
//for (int i = 0; i < N; i++) {
//cout << lambdas[i];
//cout << " ";
//}
//cout << endl;
//for (int i = 0; i < M; i++) {
//cout << queueSizes[i];
//cout << " ";
//}
//cout << endl;
//for (int i = 0; i < M; i++) {
//cout << mus[i];
//cout << " ";
//}
//cout << endl;
//return 0;