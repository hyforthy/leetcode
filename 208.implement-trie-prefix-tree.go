/*
 * @lc app=leetcode id=208 lang=golang
 *
 * [208] Implement Trie (Prefix Tree)
 *
 * https://leetcode.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (40.92%)
 * Likes:    2046
 * Dislikes: 36
 * Total Accepted:    218.1K
 * Total Submissions: 519.6K
 * Testcase Example:  '["Trie","insert","search","search","startsWith","insert","search"]\n[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * Implement a trie with insert, search, and startsWith methods.
 *
 * Example:
 *
 *
 * Trie trie = new Trie();
 *
 * trie.insert("apple");
 * trie.search("apple");   // returns true
 * trie.search("app");     // returns false
 * trie.startsWith("app"); // returns true
 * trie.insert("app");
 * trie.search("app");     // returns true
 *
 *
 * Note:
 *
 *
 * You may assume that all inputs are consist of lowercase letters a-z.
 * All inputs are guaranteed to be non-empty strings.
 *
 *
 */

// @lc code=start

type Trie struct {
	Node  [26]*Trie
	Total int
}

/** Initialize your data structure here. */
func Constructor() Trie {
	return Trie{}
}

/** Inserts a word into the trie. */
func (this *Trie) Insert(word string) {
	l1 := len(word)
	if l1 <= 0 {
		return
	}

	p := this
	for i := 0; i < l1; i++ {
		id := word[i] - 'a'
		if p.Node[id] == nil {
			p.Node[id] = &Trie{}
		}

		p = p.Node[id]
	}

	if p != this {
		p.Total = 1
	}

	this.Total++
}

/** Returns if the word is in the trie. */
func (this *Trie) Search(word string) bool {
	l1 := len(word)
	if l1 <= 0 {
		return true
	}

	p := this
	for i := 0; i < l1; i++ {
		id := word[i] - 'a'
		if p.Node[id] == nil {
			return false
		}
		p = p.Node[id]
	}
	if p.Total != 1 {
		return false
	}

	return true
}

/** Returns if there is any word in the trie that starts with the given prefix. */
func (this *Trie) StartsWith(prefix string) bool {
	l1 := len(prefix)
	if l1 <= 0 {
		return true
	}

	p := this
	for i := 0; i < l1; i++ {
		id := prefix[i] - 'a'
		if p.Node[id] == nil {
			return false
		}
		p = p.Node[id]
	}

	return true
}

/**
 * Your Trie object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(word);
 * param_2 := obj.Search(word);
 * param_3 := obj.StartsWith(prefix);
 */
// @lc code=end
