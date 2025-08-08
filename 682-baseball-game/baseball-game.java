class Solution {
    public int calPoints(String[] op) {
        int n = op.length;
        ArrayList<Integer> ans = new ArrayList<>();

        for(int i=0; i<n; i++){
            if(op[i].equals("+")){
                ans.add(ans.get(ans.size()-1)+ans.get(ans.size()-2));
            }
            else if(op[i].equals("D")){
                ans.add(ans.get(ans.size()-1)*2);
            }
            else if(op[i].equals("C")){
                ans.remove(ans.get(ans.size()-1));
            }
            else{
                ans.add(Integer.parseInt(op[i]));
            }
        }

        int sum = 0;
        for(int i=0; i<ans.size(); i++){
            sum += ans.get(i);
        }

        return sum;
    }
}
