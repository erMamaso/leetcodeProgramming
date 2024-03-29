class Solution {
public:
    bool unique(string s1){
        for(int i = 0; i<s1.size(); ++i){
            for(int j = i+1; j<s1.size(); ++j){
                if(s1[i] == s1[j]){
                    return false;
                }
            }
        }
        return true;
    }

    void maxLength2(vector<string>& arr, int indice, string pal, int& maximum){
        if(indice == arr.size()){
            return;
        }

        if (unique(pal+arr[indice])){
            string pal2 = pal+arr[indice];
            if(pal2.size() > maximum){
                maximum = pal2.size();
            }
            //int indice2 = indice+1;
            int i = 1;
            while(indice+i < arr.size()){
                maxLength2(arr, indice+i, pal2, maximum);
                ++i;
            }
            
            
        }
        else{
            int i = 1;
            while(indice+i < arr.size()){
                maxLength2(arr, indice+i, pal, maximum);
                ++i;
            }
        }
    }

    int maxLength(vector<string>& arr) {
        int maximum = 0;
        for(int i = 0; i<arr.size(); ++i){
            maxLength2(arr, i, "", maximum);
        }
        return maximum;
    }
};