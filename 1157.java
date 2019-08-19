class MajorityChecker {
    int[] v;

    public MajorityChecker(int[] arr) {
        v = arr;
    }
    
    public int query(int left, int right, int threshold) {
        int cnt = 1;
        int tmp = v[left];
        for (int i = left+1; i <= right; i++) {
            if (v[i] == tmp) cnt++;
            else {
                cnt--;
                if (cnt == 0) {
                    tmp = v[i];
                    cnt = 1;
                }
            }
        }
        int num = 0;
        for (int i = left; i <= right; i++) {
            num += (v[i] == tmp ? 1 : 0);
            if (num >= threshold) return tmp;
        }
        return -1;
    }
}

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker obj = new MajorityChecker(arr);
 * int param_1 = obj.query(left,right,threshold);
 */