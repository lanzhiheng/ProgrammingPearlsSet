def binary_search(array, target)
  length = array.length
  left = 0
  right = length - 1
  while (left <= right) do
    middle = (left + right) / 2
    if (array[middle] > target)
      right = middle - 1
    elsif (array[middle] < target)
      left = middle + 1
    else
      return middle
    end
  end
  return -1
end
