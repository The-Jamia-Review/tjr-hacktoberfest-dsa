class Solution {
    public static List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> list = new ArrayList<>();
        fn(0, list,new ArrayList<>(), candidates, target);
        System.out.println(list);
        return list;
    }

     public static void fn(int i,List<List<Integer>> list, List<Integer> l, int[] arr,int target){
       if(i>=arr.length){
        if(target==0) list.add(new ArrayList<>(l));
        return;
       }

       if(arr[i]<=target){
            l.add(arr[i]);
            fn(i,list,l,arr,target-arr[i]);
            l.remove(l.size()-1);
       }

       fn(i+1,list,l,arr,target);
    }
}

