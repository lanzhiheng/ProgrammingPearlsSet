require 'tk'
require 'fiddle'

libm = Fiddle.dlopen('./binary_search.so')

binary_search =  Fiddle::Function.new(libm['binarysearch'], [Fiddle::TYPE_LONG], Fiddle::TYPE_LONG)
prepare_elements =  Fiddle::Function.new(libm['prepare_elements'], [Fiddle::TYPE_VOID], Fiddle::TYPE_VOID)

puts prepare_elements.call(nil)
puts binary_search.call(100)

root = TkRoot.new { title "Hello, World!" }

button = TkButton.new(root) do
  text "test"
end

entry1 = TkEntry.new(root)
entry2 = TkEntry.new(root)

variable1 = TkVariable.new
variable2 = TkVariable.new

entry1.textvariable = variable1
entry2.textvariable = variable2

text = TkText.new(root)

entry1.place('height' => 25, 'width'  => 50, 'x' => 10, 'y'   => 10)
entry2.place('height' => 25, 'width'  => 50, 'x' => 60, 'y'   => 10)
button.place('height' => 25, 'width'  => 50, 'x' => 120, 'y'   => 10)

text.place('height' => 25, 'width'  => 150, 'x' => 10, 'y'  => 45)

text.insert('end', 'lanzhiheng')

Tk.mainloop
