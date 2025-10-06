class Solution {
    public List<List<Integer>> getSkyline(int[][] buildings) {
        
        List<Pair> list = new ArrayList<>();
        
        for(int i = 0 ; i < buildings.length ; i++){
            int st = buildings[i][0];
            int et = buildings[i][1];
            int ht = buildings[i][2];
            
            Pair p = new Pair(st,-ht);
            Pair q = new Pair(et, ht);
            list.add(p);
            list.add(q);
        }
        
        Collections.sort(list);
        List<List<Integer>> ans = new ArrayList<>();
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        pq.add(0);
        int ch = 0;
        
        for(int i= 0 ; i < list.size() ; i++){
            
            int x = list.get(i).x;
            int ht = list.get(i).ht;
            
            if(ht < 0){
                pq.add(-ht);
            }else{
                pq.remove(ht);
            }
            
            if(ch != pq.peek()){
                List<Integer> li = new ArrayList<>();
                li.add(x);
                li.add(pq.peek());
                ans.add(li);
                ch = pq.peek();
            }
        }
        
        return ans;
        
        
    }
    
    class Pair implements Comparable<Pair>{
        int x;
        int ht;
        
        Pair(int x , int ht){
            this.x = x;
            this.ht = ht;
        }
        
        public int compareTo(Pair other){
            if(this.x != other.x){
                return this.x - other.x;
            }else{
                return this.ht - other.ht;
            }
        }
    }
}