require 'test-unit'
require './binary_search'

class TestBinarySearch < Test::Unit::TestCase
  def test_binary_search
    [1000, 2000, 3000, 5000, 10000].each do |n|
      puts "test #{n} number"
      array = (0...n).map {|i| i * 10}

      array.each_with_index do |item, index|
        assert binary_search(array, item) == index, "expected"
      end
    end
  end
end
