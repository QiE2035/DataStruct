namespace Sort {

template <typename T>
void InsertSort(vector<T> &R) {
    auto tmp = R[0];
    for (int i = 2; i < R.size(); i++) {
        R[0] = R[i];
        int j = i - 1;
        while (R[0] < R[j]) {
            R[j + 1] = R[j];
            j--;
        }
        R[j + 1] = R[0];
    }
    R[0] = tmp;
}

} // namespace Sort