class Solution {
    fun firstUniqChar(s: String): Int
    {
        val counts = IntArray(26)

        for (c in s) {
            counts[c - 'a']++
        }

        var i = 0;
        for (c in s) {
            if (counts[c - 'a'] == 1) return i
            else i++
        }
        

        return -1
    }
}