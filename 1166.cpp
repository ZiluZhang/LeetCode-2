class FileSystem {
public:
    unordered_map<string, int> m;
    FileSystem() {
        m.clear();
    }
    
    bool createPath(string path, int value) {
        if (path.length() == 0 || path == "/" || path[0] != '/') {
            return false;
        }
        int idx = path.find_last_of('/');
        string parent = path.substr(0, idx);
        if (parent.size() > 0 && m.count(parent) == 0) {
            return false;
        }
        if (m.count(path)) return false;
        m[path] = value;
        return true;
    }
    
    int get(string path) {
        if (m.count(path) == 0) {
            return -1;
        } else {
            return m[path];
        }
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */