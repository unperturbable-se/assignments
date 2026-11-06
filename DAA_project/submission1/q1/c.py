def merge_sort(array, left, right):
    if left >= right:
        return 0
    mid = (left + right) // 2
    inv = merge_sort(array, left, mid) + merge_sort(array, mid + 1, right)
    return inv + merge(array, left, mid, right)

def merge(array, left, mid, right):
    k, i, j, inv = [], left, mid + 1, 0
    while i <= mid and j <= right:
        if array[i] <= array[j]:
            k.append(array[i])
            i += 1
        else:
            k.append(array[j])
            j += 1
            inv += (mid + 1 - i)
    k.extend(array[i:mid + 1] or array[j:right + 1])
    array[left:right + 1] = k
    return inv

arr = [4, 3, 23, 4, 4, 3, 4, -2, 4, 2, 3]
print("Number of inversions: ", merge_sort(arr, 0, len(arr) - 1))