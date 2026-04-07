class Robot {
public:
    int width, height;
    int x, y;
    int dir; // 0=East, 1=North, 2=West, 3=South
    
    vector<string> dirs = {"East", "North", "West", "South"};
    vector<pair<int,int>> move = {{1,0},{0,1},{-1,0},{0,-1}};
    
    Robot(int w, int h) {
        width = w;
        height = h;
        x = 0;
        y = 0;
        dir = 0;
    }
    
    void step(int num) {
        int cycle = 2 * (width + height - 2);
        num %= cycle;
        
        // special case
        if(num == 0 && (x == 0 && y == 0)) {
            dir = 3; // South
            return;
        }
        
        while(num--) {
            int nx = x + move[dir].first;
            int ny = y + move[dir].second;
            
            if(nx < 0 || nx >= width || ny < 0 || ny >= height) {
                dir = (dir + 1) % 4; // turn
                nx = x + move[dir].first;
                ny = y + move[dir].second;
            }
            
            x = nx;
            y = ny;
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        return dirs[dir];
    }
};
/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */