class Robot {
public:
  int pos, tot, l1, l2, l3, max_y, max_x;
  bool flag = true;
  
  Robot(int w, int h) {
    pos = 0;
    max_y = h - 1, max_x = w - 1; 
    l1  = w;
    l2  = l1 + h - 1;
    l3  = l2 + w - 1;
    tot = l3 + h - 2;
  }
    
  void step(int num){
    flag = false;
    pos = (pos + num)%tot;
  }
    
  vector<int> getPos() {
    if(pos < l1) return {pos, 0};
    if(pos < l2) return {max_x, pos - l1 + 1};
    if(pos < l3) return {l3 - pos - 1, max_y};
    
    return {0 , tot - pos};      
  }
    
  string getDir() {
    if(flag) return "East";
    
    if(pos == 0) return "South";
    if(pos < l1) return "East";
    if(pos < l2) return "North";
    if(pos < l3) return "West";
    
    return "South"; 
  }
};