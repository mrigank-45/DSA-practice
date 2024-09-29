// Given an array of strings strs, group the anagrams together.

Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output: [eat,tea,ate,bat,tan,nat]

// Approach

sorted = [aet, aet, ant , aet, ant, abt]  

// unordered_map
aet-> 0,1,3 
ant-> 2,4
abt-> 5

Q**** // alternate approach to grp anagrams: vector<vector<string>>
[[eat,tea,ate],[tan,nat],[bat]]  // how and time complexity difference?

// vector<string> order
[aet,ant,abt]

Q****** // worst case time complexoty to push in vector?

// vector<string> ans
[eat,tea,ate,bat,tan,nat]

TC: o(n*k*log k)
SC: o(n*k*)
