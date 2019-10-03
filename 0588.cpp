class FileSystem {
public:
    unordered_map<string, string> files;
    unordered_map<string, set<string>> dirs;
    FileSystem() {
        dirs["/"];
    }
    
    vector<string> ls(string path) {
        if (files.count(path)) {
            int idx = path.find_last_of('/');
            return {path.substr(idx+1)};
        }
        auto t = dirs[path];
        return vector<string>(t.begin(), t.end());
    }
    
    void mkdir(string path) {
        istringstream is(path);
        string t = "", dir = "";
        while (getline(is, t, '/')) {
            if (t.length() == 0) continue;
            if (dir.length() == 0) dir = "/";
            dirs[dir].insert(t);
            if (dir.length() > 1) dir += "/";
            dir += t;
        }
    }
    
    void addContentToFile(string filePath, string content) {
        int idx = filePath.find_last_of('/');
        string dir = filePath.substr(0, idx);
        string fileName = filePath.substr(idx+1);
        if (dir.length() == 0) dir = "/";
        if (dirs.count(dir) == 0) mkdir(dir);
        dirs[dir].insert(fileName);
        files[filePath].append(content);
        return;
    }
    
    string readContentFromFile(string filePath) {
        return files[filePath];
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */