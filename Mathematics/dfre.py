class SegmentTree:
    def __init__(self, size):
        self.size = size
        self.tree = [0] * (4 * size)

    def update(self, idx, value, node=1, left=0, right=-1):
        if right == -1:
            right = self.size - 1

        if left == right:
            self.tree[node] += value
            return

        mid = (left + right) // 2
        if idx <= mid:
            self.update(idx, value, 2 * node, left, mid)
        else:
            self.update(idx, value, 2 * node + 1, mid + 1, right)
        self.tree[node] = self.tree[2 * node] + self.tree[2 * node + 1]

    def query(self, ql, qr, node=1, left=0, right=-1):
        if right == -1:
            right = self.size - 1

        if ql <= left and qr >= right:
            return self.tree[node]

        if ql > right or qr < left:
            return 0

        mid = (left + right) // 2
        return self.query(ql, qr, 2 * node, left, mid) + self.query(ql, qr, 2 * node + 1, mid + 1, right)


def solve(t, test_cases):
    for _ in range(t):
        n = test_cases[_][0]
        arr = test_cases[_][1]

        # Create segment tree
        seg_tree = SegmentTree(4 * n)

        result = 0

        for i in range(n):
            # Update segment tree
            seg_tree.update(arr[i], 1)

            # Calculate left and right limits
            left_limit = seg_tree.query(1, arr[i] - 1)
            right_limit = seg_tree.query(arr[i] + 1, n)

            # Calculate the number of subarrays with arr[i] as the minimum element
            num_subarrays = (i - left_limit + 1) * (right_limit - i + 1)

            # Update the result
            result += num_subarrays

        print(result)


# Example usage
t = 2
test_cases = [
    (4, [4, 8, 7,2]),
    (3, [3, 2, 1])
]
solve(t, test_cases)
