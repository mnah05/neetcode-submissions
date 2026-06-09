public class TimeMap {

    private Map<String, List<Pair>> Store;

    public TimeMap() {
        Store = new HashMap<>();
    }

    public void set(String key, String value, int timestamp) {
        //if key appears first time create an empty list
        Store.putIfAbsent(key, new ArrayList<>());
        //then add that key's value into the list
        Store.get(key).add(new Pair(value, timestamp));
    }

    public String get(String key, int timestamp) {
        //Get value list of the key
        List<Pair> values = Store.getOrDefault(key, new ArrayList<>());
        String res = "";
        int l = 0,
            r = values.size() - 1;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (values.get(mid).timestamp <= timestamp) {
                res = values.get(mid).value;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }

    private static class Pair {

        String value;
        int timestamp;

        Pair(String value, int timestamp) {
            this.value = value;
            this.timestamp = timestamp;
        }
    }
}
