        vector<vector<int>> dir={{0,-1},{-1,-1},{-1,0},{0,0}}; //黑格子的 四个格子的左上角的 相对黑个字的坐标
        for(vector<int> black : coordinates){
            for(int k=0;k<4;k++){ 
                int nx=black[0]+dir[k][0];  //左上角的坐标
                int ny=black[1]+dir[k][1];
                if(nx<0 || ny<0 || nx>=m-1 || ny>=n-1) continue;
                positon[{nx,ny}]++;
            }
        }