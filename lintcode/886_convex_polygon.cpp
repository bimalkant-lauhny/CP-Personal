class Solution {
    public:
        /**
         * @param point: a list of two-tuples
         * @return: a boolean, denote whether the polygon is convex
         */
        int crossProduct(vector<int> &p1, vector<int> &p2, vector<int> &p3) {
            return ((p2[0] - p1[0]) * (p3[1] - p2[1])) - 
                ((p3[0] - p2[0]) * (p2[1] - p1[1]));
        }

        bool isConvex(vector<vector<int>> &point) {
            bool negative = false, positive = false;
            int cp = 0;
            for (int i=0; i<point.size(); ++i) {
                cp = crossProduct(point[i], point[(i+1)%point.size()], 
                        point[(i+2)%point.size()]); 
                if (cp < 0)
                    negative = true;
                else if (cp > 0)
                    positive = true;
            }

            if ((!negative && !positive) || (negative && positive))
                return false;
            return true;
        }
};
