class Vector2D {
public:
    vector<vector<int>> data;
    int x, y;
    Vector2D(vector<vector<int>>& v) {
        data = v;
        x = 0;
        y = 0;
    }
    
    int next() {
        hasNext();
        return data[x][y++];
    }
    
    bool hasNext() {
        while (x < data.size() && y == data[x].size()) {
            x++;
            y = 0;
        }
        return x < data.size();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */