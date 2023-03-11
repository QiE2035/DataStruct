namespace Sort {

template <typename T>
void BubbleSort(vector<T> &R) {
    for (int i = 1; i < R.size(); i++) {
        bool flag = true;
        for (int j = 1; j < R.size() - 1; j++)
            if (R[j] > R[j + 1]) {
                auto x = R[j];
                R[j] = R[j + 1];
                R[j + 1] = x;
                flag = false;
            }
        if (flag)
            break;
    }
}

} // namespace Sort