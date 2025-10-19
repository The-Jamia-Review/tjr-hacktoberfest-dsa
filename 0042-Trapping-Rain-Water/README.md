# 🧩 Trapping Rain Water

## 📘 Problem Description

Given `n` non-negative integers representing an elevation map where the width of each bar is `1`, compute how much water it can trap after raining.

### Example 1:
**Input:**
height = [0,1,0,2,1,0,1,3,2,1,2,1]

**Output:**
6

**Explanation:**
The above elevation map (black section) is represented by array `[0,1,0,2,1,0,1,3,2,1,2,1]`.  

In this case, 6 units of rain water (blue section) are being trapped.

### Example 2:
**Input:**
height = [4,2,0,3,2,5]

**Output:**
9



---

## 💡 Approach

To calculate the trapped water at each index, we need to know:
- The **maximum height to the left** of that index.
- The **maximum height to the right** of that index.

The water trapped at position `i` will be:
water[i] = min(maxLeft[i], maxRight[i]) - height[i]


### Steps:
1. Precompute two arrays:
   - `left[i]` → maximum height from the right side.
   - `right[i]` → maximum height from the left side.
2. Iterate through the array and sum up trapped water using the above formula.

---

## 🧮 Complexity Analysis

| Type | Complexity |
|------|-------------|
| **Time Complexity** | O(n) — We traverse the array three times. |
| **Space Complexity** | O(n) — Two auxiliary arrays are used (`left[]` and `right[]`). |

---

## 🧠 Intuition

The height of water above each block depends on the **tallest boundaries** on its left and right sides.  
If we know these two values, the trapped water is simply the difference between the smaller boundary and the block’s height.

---