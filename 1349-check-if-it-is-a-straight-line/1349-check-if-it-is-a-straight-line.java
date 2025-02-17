class Solution {
    public boolean checkStraightLine(int[][] coordinates) {
        // Get the first two points
        int x1 = coordinates[0][0], y1 = coordinates[0][1];
        int x2 = coordinates[1][0], y2 = coordinates[1][1];
        
        // Calculate the differences for the first two points
        int dx = x2 - x1;
        int dy = y2 - y1;
        
        // Iterate over the remaining points
        for (int i = 2; i < coordinates.length; i++) {
            int x3 = coordinates[i][0], y3 = coordinates[i][1];
            
            // Check if the cross product of (x2 - x1) and (y2 - y1) is the same as (x3 - x2) and (y3 - y2)
            if ((y3 - y2) * dx != (x3 - x2) * dy) {
                return false;
            }
        }
        
        return true;
    }
}