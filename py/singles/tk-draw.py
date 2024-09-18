import tkinter as tk

def draw_circle(canvas):
    canvas.delete("all")
    canvas.create_oval(50, 50, 150, 150, outline="blue", width=2)

def draw_square(canvas):
    canvas.delete("all")
    canvas.create_rectangle(50, 50, 150, 150, outline="red", width=2)

def main():
    root = tk.Tk()
    root.title("Draw Shapes")

    canvas = tk.Canvas(root, width=200, height=200)
    canvas.pack()

    button_frame = tk.Frame(root)
    button_frame.pack()

    circle_button = tk.Button(button_frame, text="Draw Circle", command=lambda: draw_circle(canvas))
    circle_button.pack(side="left")

    square_button = tk.Button(button_frame, text="Draw Square", command=lambda: draw_square(canvas))
    square_button.pack(side="left")

    root.mainloop()

if __name__ == "__main__":
    main()