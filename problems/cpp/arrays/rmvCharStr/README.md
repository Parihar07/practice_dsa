# Remove Character from String

## Problem Description
Given a string and a character, remove all occurrences of that character from the string.

### Input Format
- A string `str` (1 <= str.length() <= 10000)
- A character `ch` to be removed

### Output Format
- Return a new string with all occurrences of `ch` removed

### Constraints
- String contains only printable ASCII characters
- Character `ch` is a single character
- If all characters are removed, return empty string

## Examples

### Example 1
**Input:**
```
str = "abxxcdfexxd"
ch = 'x'
```
**Output:**
```
"abcdfed"
```

### Example 2
**Input:**
```
str = "hello world"
ch = 'l'
```
**Output:**
```
"heo word"
```

### Example 3
**Input:**
```
str = "aaaa"
ch = 'a'
```
**Output:**
```
""
```

## Approaches

### Approach 1: Manual Loop (Basic)
```cpp
string rmvCharStr(string str, char ch) {
    string result;
    int i = 0;
    while (str[i] != '\0') {
        if(str[i] != ch)
            result.push_back(str[i]);
        i++;
    }
    return result;
}
```
**Time Complexity:** O(n)  
**Space Complexity:** O(n)  
✓ Works correctly  
⚠️ Manual indexing, uses `'\0'` check

---

### Approach 2: Range-based For Loop (Recommended for Learning)
```cpp
string rmvCharStr(string str, char ch) {
    string result;
    for(char c : str) {
        if(c != ch)
            result.push_back(c);
    }
    return result;
}
```
**Time Complexity:** O(n)  
**Space Complexity:** O(n)  
✅ Cleaner syntax  
✅ No manual indexing  
✅ More readable

---

### Approach 3: STL Remove-Erase Idiom (Industry Standard)
```cpp
#include <algorithm>

string rmvCharStr(string str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());
    return str;
}
```
**Time Complexity:** O(n)  
**Space Complexity:** O(1) - modifies in-place  
✅ One-liner!  
✅ Standard library approach  
✅ Most efficient (no extra allocation)  
✅ Shows C++ expertise

**How it works:**
1. `remove()` shifts all non-matching elements to the front
2. Returns iterator pointing to the "new end"
3. `erase()` removes elements from that point to actual end

---

### Approach 4: With Memory Optimization
```cpp
string rmvCharStr(string str, char ch) {
    string result;
    result.reserve(str.size());  // Pre-allocate memory
    for(char c : str) {
        if(c != ch)
            result.push_back(c);
    }
    return result;
}
```
**Time Complexity:** O(n)  
**Space Complexity:** O(n)  
✅ Avoids multiple reallocations  
✅ Better performance for large strings

---

## Comparison Summary

| Approach | Time | Space | Readability | Performance | Interview Score |
|----------|------|-------|-------------|-------------|-----------------|
| Manual Loop | O(n) | O(n) | 6/10 | Good | 6/10 |
| Range-based | O(n) | O(n) | 9/10 | Good | 8/10 |
| STL Remove-Erase | O(n) | **O(1)** | 7/10 | **Best** | **10/10** |
| With Reserve | O(n) | O(n) | 8/10 | Very Good | 9/10 |

## Key Learnings

### 1. String vs Array
- Strings in C++ are mutable (unlike Java)
- Can modify in-place using `erase()`
- `push_back()` may cause reallocations

### 2. Memory Efficiency
- Creating new string: O(n) space
- In-place modification: O(1) extra space
- `reserve()` prevents multiple reallocations

### 3. C++ STL Algorithms
- `remove()` - shifts elements, doesn't actually erase
- Always pair with `erase()` for actual removal
- This pattern is called "remove-erase idiom"

### 4. Interview Tips
- **Start simple** - show you can solve it
- **Optimize** - mention STL approach
- **Discuss trade-offs** - readability vs performance
- **Ask clarifications** - modify in-place vs new string?

## Related Problems
- Remove duplicates from string
- Remove vowels from string
- Filter characters based on condition
- String compression

## Complexity Analysis

### Time Complexity: O(n)
- Must scan entire string once
- Each character processed exactly once

### Space Complexity: 
- **New string approach:** O(n) - worst case no characters removed
- **In-place approach:** O(1) - only modifying existing string

## Test Cases Covered
✓ Multiple occurrences  
✓ Character in middle  
✓ Removing all characters  
✓ Character not present  
✓ Empty string  
✓ Single character (match and no match)  
✓ Special characters (spaces)
