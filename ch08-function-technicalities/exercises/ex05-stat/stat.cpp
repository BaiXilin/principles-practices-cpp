#include "../../../std_lib_facilities.h"
#include <algorithm>

struct all_stats {
    double max;
    double min;
    double median;
    double mean;
};

all_stats find_stat(const vector<double> &);
void find_stat(const vector<double> &, double &, double &, double &, double &);

double find_max(const vector<double> &);
double find_min(const vector<double> &);
double find_median(const vector<double> &);
double find_mean(const vector<double> &);

int main() {
    vector<double> samples{76.3, 58.6, 43.2, 62.0, 83.6, 33.1, 29.0, 46.5, 18.7, 32.2};

    all_stats ret = find_stat(samples);
    cout << "Result returned by struct: " << "\n";
    cout << "max = " << ret.max << "\n";
    cout << "min = " << ret.min << "\n";
    cout << "median = " << ret.median << "\n";
    cout << "mean = " << ret.mean << "\n\n";

    double max, min, median, mean;
    find_stat(samples, max, min, median, mean);
    cout << "Result returned by double references: " << "\n";
    cout << "Result returned by struct: " << "\n";
    cout << "max = " << max << "\n";
    cout << "min = " << min << "\n";
    cout << "median = " << median << "\n";
    cout << "mean = " << mean << "\n";
}

all_stats find_stat(const vector<double> &samples) {
    all_stats result {
        max: find_max(samples),
        min: find_min(samples),
        median: find_median(samples),
        mean: find_mean(samples),
    };
    return result;
}

void find_stat(const vector<double> &samples, double &max, double &min, double &median, double &mean) {
    max = find_max(samples);
    min = find_min(samples);
    median = find_median(samples);
    mean = find_mean(samples);
}

double find_max(const vector<double> & samples) {
    double max = samples[0];
    for(int i = 0; i < samples.size(); i++) {
        if(samples[i] > max) {
            max = samples[i];
        }
    }
    return max;
}

double find_min(const vector<double> & samples) {
    double min = samples[0];
    for(int i = 0; i < samples.size(); i++) {
        if(samples[i] < min) {
            min = samples[i];
        }
    }
    return min;
}

double find_median(const vector<double> &samples) {
    vector<double> sorted(samples.size());
    partial_sort_copy(begin(samples), end(samples), begin(sorted), end(sorted));

    double median;
    if(sorted.size() % 2) {
        median = (sorted[sorted.size() - 1] + sorted[sorted.size()]) / 2;
    } else {
        median = sorted[sorted.size() / 2];
    }
    return median;
}

double find_mean(const vector<double> &samples) {
    double sum = 0;
    for(int i = 0; i < samples.size(); i++) {
        sum += samples[i];
    }
    return sum / samples.size();
}