require 'tk'

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
