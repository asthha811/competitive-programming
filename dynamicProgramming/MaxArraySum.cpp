#include <bits/stdc++.h>

using namespace std;
//link of question->https://www.hackerrank.com/challenges/max-array-sum/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dynamic-programming

vector<string> split_string(string);
int maxsum=0;
int dp[1000000]={0};
int  calculateSum(vector<int>&arr,int index,int n){
    if(index>=n){
        return 0;
    }
     int k=0;
     int l=0;

     if(dp[index]!=-1){
        return dp[index];
    }
   else{
         k=arr[index]+calculateSum(arr,index+2,n);
         l=calculateSum(arr,index+1,n);
        dp[index]=max(k,l);
    }










    return dp[index];

}

// Complete the maxSubsetSum function below.
int maxSubsetSum(vector<int> &arr) {
    int n=arr.size();

    return calculateSum(arr,0,n);



}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        dp[i]=-1;
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int res = maxSubsetSum(arr);

    fout << res << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
