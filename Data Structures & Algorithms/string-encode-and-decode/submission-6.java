class Solution {

    public String encode(List<String> str) {
        StringBuilder sb = new StringBuilder();

        for (String s : str) {
            sb.append(s.length())
                    .append('#')
                    .append(s);
        }

        return sb.toString();
    }

    public List<String> decode(String s) {
        List<String> result = new ArrayList<>();
        int i = 0;
        while ( i < s.length()){
            int j = i;
            while(s.charAt(j) != '#'){
                j+=1;
            }
            int len = Integer.parseInt(s.substring(i, j));
            String word = s.substring(j + 1, j + 1 + len);
            result.add(word);
            i = j + 1 + len;
        }
        return result;
    }
}
