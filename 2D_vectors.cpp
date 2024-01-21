#include<bits/stdc++.h>

using namespace std;

// row with maximum ones (LC-2643)
vector<int> max_ones(vector<vector<int>> &nums) {
    int oneCount=0, rowCount=0;
    for(int i=0; i<nums.size(); ++i) {
        int count=0;
        for(int j=0; j<nums[i].size(); ++j) {
            if(nums[i][j] == 1)
                count++;
        }
        if(count > oneCount) {
            oneCount = count;
            rowCount = i;
        }
    }
    vector<int> ans;
    ans.push_back(rowCount);
    ans.push_back(oneCount);
    return ans;
}

// rotate image (LC-48)
void rotate_image(vector<vector<int>> &nums) {
    for(int i=0; i<nums.size(); ++i) {
        for(int j=i; j<nums[i].size(); ++j)
            swap(nums[i][j], nums[j][i]);
    }
    for(int i=0; i<nums.size(); ++i)
        reverse(nums[i].begin(), nums[i].end());
}

// spiral matrix (LC-54)
vector<int> spiral_order(vector<vector<int>> &nums) {
    vector<int> ans;
    int rows = nums.size(), cols = nums[0].size();
    int total_elements = rows * cols;
    int starting_row = 0, starting_col = 0;
    int ending_row = rows - 1, ending_col = cols - 1;
    int count = 0;
    while (count < total_elements) {
        for (int i = starting_col; i <= ending_col && count < total_elements; ++i) {
            ans.push_back(nums[starting_row][i]);
            count++;
        }
        starting_row++;
        for (int i = starting_row; i <= ending_row && count < total_elements; ++i) {
            ans.push_back(nums[i][ending_col]);
            count++;
        }
        ending_col--;
        for (int i = ending_col; i >= starting_col && count < total_elements; --i) {
            ans.push_back(nums[ending_row][i]);
            count++;
        }
        ending_row--;
        for (int i = ending_row; i >= starting_row && count < total_elements; --i) {
            ans.push_back(nums[i][starting_col]);
            count++;
        }
        starting_col++;
    }
    return ans;
}

int main() {

    int rows, cols;
    cout << "enter rows ans columns : ";
    cin >> rows >> cols;
    cout << "enter your elements in matrix : ";
    vector<vector<int>> nums(rows, vector<int>(cols));
    for(int i=0; i<rows; ++i) {
        for(int j=0; j<cols; ++j)
            cin >> nums[i][j];
    }

    // vector<int> result = max_ones(nums);
    // cout << "the maximum ones are found in : " << "[ ";
    // for(int r:result)
    //     cout << r << " ";
    // cout << "]" << endl;

    // rotate_image(nums);
    // cout << "Rotated 2D vector:" << endl << "[ ";
    // for (const auto& row : nums) {
    //     cout << "[ ";
    //     for (int x : row)
    //         cout << x << " ";
    //     cout << "]";
    // }
    // cout << " ]" << endl;

    vector<int> result = spiral_order(nums);
    cout << "here is your spiral order of the given matrix : " << endl << "[ ";
    for(int r:result)
        cout << r << " ";
    cout << "]" << endl;

    return 0;
}