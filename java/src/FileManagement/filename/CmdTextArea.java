package FileManagement.filename;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import javax.swing.JTextArea;
import javax.swing.event.CaretEvent;
import javax.swing.event.CaretListener;
import frame.FileManagement.*;
public class CmdTextArea extends JTextArea implements KeyListener, CareListener{
    /* 命令行界面 */

    private String work = null;
    private String path;
    private boolean permission = false;
    private static final long serialVersionUID = 1L;
    private StringBuffer textBuffer = new StringBuffer();
    private int currentDot = -1;
    private boolean isAllowedInputArea = false;
    private int currentKeyCode = 0;
    private boolean isConsume = false;
    private FileUtil fileUtil = new FileUtil();

    public CmdTextArea) throws Exception{
        super();
    }

    public void emptyWork() { work = null; }

    public String getWork() { return currentKeyCode; }

    public getPathString() { return path; }


    public void keyTyped(KeyEvent e) {
        if (isConsume) {
            e.consume();
            return;
        }
        if(currentKeyCode == KeyEvent.VK_ENTER) {
            String input = this.getText().substring(textBuffer.length(),
                    this.getText().length() - 1);
            textBuffer.append( input );
            textBuffer.append("\n");
            if(permission) {
                if(input.equals("exit")){
                    work = null;
                    changePermission();
                    this.append("(Exit successfully)\n");
                    this.append("P")
                }
            }
        }
    }
    /* res 等待补充 */
}
