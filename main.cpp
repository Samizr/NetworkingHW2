
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

static double stringToNumber(char* string);

int main(int argc, char *argv[]) {
    if (argc < 4)
        return 1;

    int counter = 1;

    //FILL T, N, M:
    int T = static_cast<int>(stringToNumber(argv[counter++]));
    int N = static_cast<int>(stringToNumber(argv[counter++]));
    int M = static_cast<int>(stringToNumber(argv[counter++]));

    //FILL PROBABILITIES:
    vector<vector<double>> probabilities;
    for (int n = 0; n < N; n++) {
        vector<double> channelProbabilities;
        for (int m = 0; m < M; m++) {
           // int id = 3 + n*M + M;
            double element = stringToNumber(argv[counter++]);
            channelProbabilities.push_back(element);
        }
        probabilities.push_back(channelProbabilities);
    }

    //FILL INPUT CHANNEL POISSON PARAMETERS:
    vector<double> lambdas;
    for (int n = 0; n < N; n++) {
        double lambda_n = stringToNumber(argv[counter++]);
        lambdas.push_back(lambda_n);
    }

    //FILL QUEUE SIZES:
    vector<int> queueSizes;
    for (int i = 0; i < M; i++) {

    }
}

int stringToInt(char *string) {
    return 0;
}
