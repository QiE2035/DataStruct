namespace Sort {

template <typename T>
void SelectSort(vector<T> &R) {
    auto tmp = R[0];
    for (int i = 1; i < R.size(); i++) {
        int k = i;
        for (int j = i + 1; j < R.size(); j++)
            if (R[j] < R[k])
                k = j;
        if (k != i) {
            auto x = R[i];
            R[i] = R[k];
            R[k] = x;
        }
    }
    R[0] = tmp;
}

} // namespace Sort