import curses
import curses.ascii as ca

def main(screen):
    curses.start_color()
    
    num_rows, num_cols = screen.getmaxyx()
    window = curses.newwin(num_rows, num_cols, 0, 0)
    key_presses = []
    window.addstr(0,0,"Hello")
    window.refresh()

    # when enter is pressed, go down 1 line
    curr_col = 0
    while True:
        c = screen.getch()
        if chr(c) == '\n':
            # refresh key press buffer
            key_presses = []
            curr_col += 1
            window.addstr(curr_col,len(key_presses), '')
        elif c == ca.ESC:
            break
        else:
            key_presses.append(chr(c))
            window.addstr(curr_col,len(key_presses) - 1,chr(c))

        window.refresh()

    

if __name__ == "__main__":
    curses.wrapper(main)