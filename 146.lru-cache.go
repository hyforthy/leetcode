/*
 * @lc app=leetcode id=146 lang=golang
 *
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (27.55%)
 * Likes:    4255
 * Dislikes: 182
 * Total Accepted:    408.7K
 * Total Submissions: 1.4M
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and put.
 * 
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reached its capacity, it should invalidate the least recently
 * used item before inserting a new item.
 * 
 * The cache is initialized with a positive capacity.
 * 
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 * 
 * Example:
 * 
 * 
 * LRUCache cache = new LRUCache( 2 /* capacity */ );
 * 
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // returns 1
 * cache.put(3, 3);    // evicts key 2
 * cache.get(2);       // returns -1 (not found)
 * cache.put(4, 4);    // evicts key 1
 * cache.get(1);       // returns -1 (not found)
 * cache.get(3);       // returns 3
 * cache.get(4);       // returns 4
 * 
 * 
 * 
 * 
 */

// @lc code=start
func Constructor(capacity int) LRUCache {
	m := make(map[int]*CacheNode)
	c := LRUCache{Cap: capacity, Map: m}
	return c
}

func (this *LRUCache) Get(key int) int {
	found, ok := this.Map[key]
	if !ok {
		return -1
	}
	if this.Head == found {
		return found.Val
	}
	if this.Tail == found {
		this.Tail = found.Prev
	}
	// move found to head
	if found.Next != nil {
		found.Next.Prev = found.Prev
	}
	if found.Prev != nil {
		found.Prev.Next = found.Next
	}
	this.Head.Prev, found.Next = found, this.Head
	this.Head = found
	return found.Val
}

func (this *LRUCache) Put(key int, value int) {
	found, ok := this.Map[key]
	if ok {
		found.Val = value
		_ = this.Get(found.Key) // to move found node to head
		return
	}

	// add to head
	n := &CacheNode{Key: key, Val: value}

	if len(this.Map) == 0 {
		this.Tail = n
	} else {
		this.Head.Prev, n.Next = n, this.Head
	}
	this.Map[key], this.Head = n, n
	if this.Cap == this.Len {
		delete(this.Map, this.Tail.Key)
		this.Len, this.Tail = this.Len-1, this.Tail.Prev
		this.Tail.Next = nil
	}
	this.Len++
}

type CacheNode struct {
	Next *CacheNode
	Prev *CacheNode
	Key  int
	Val  int
}

type LRUCache struct {
	Cap  int
	Len  int
	Head *CacheNode
	Tail *CacheNode
	Map  map[int]*CacheNode
}


/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
// @lc code=end

