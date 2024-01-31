class Solution {
public:

    string turnToJustification(vector<string> text, int maxW){
        int wordSize = 0;
        for(int i = 0; i<text.size(); ++i){
            wordSize += text[i].size();
        }
        int nSpaces = maxW - wordSize;
        string s = "";
        if(text.size() == 1){
            string spaces(maxW-text[0].size(), ' ');
            return text[0] + spaces;
        }
        int hmSpaces = (nSpaces / (text.size()-1));
        int exSpaces = nSpaces % (text.size()-1);

        for(int i = 0; i<text.size()-1; ++i){
            string spaces(hmSpaces, ' ');
            s = s+text[i]+spaces;
            if(exSpaces > 0){
                s+=" ";
                exSpaces--;
            }
        }
        s+=text[text.size()-1];
        return s;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<vector<string>> lines;
        vector<string> oneLine;
        int oneLineWidth = 0;
        int aux;
        for(int i=0; i<words.size(); ++i){
            if(oneLine.size() == 0) aux = oneLineWidth + words[i].size();
            else aux = oneLineWidth + words[i].size() + 1;
            
            if(aux <= maxWidth){
                if(oneLine.size() == 0){
                    oneLine.push_back(words[i]);
                    oneLineWidth += words[i].size();
                }
                else{
                    oneLine.push_back(words[i]);
                    oneLineWidth = oneLineWidth + words[i].size() + 1; //extra space, atleast one.
                }
            }
            else{
                --i;
                lines.push_back(oneLine);
                oneLine.clear();
                oneLineWidth = 0;
            }
        }

        vector<string> res;
        for(int i = 0; i<lines.size(); ++i) res.push_back(turnToJustification(lines[i], maxWidth));

        string s = oneLine[0];
        for(int i = 1; i<oneLine.size(); ++i){
            s = s + " " + oneLine[i];
        }
        string spaces(maxWidth - s.size(), ' ');
        s+=spaces;

        res.push_back(s);

        return res;
    }
};