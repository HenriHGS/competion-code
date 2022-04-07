package frame.FileManagement.fileFrame;
import frame.FileManagement.*;
import javax.swing.*;
import javax.swing.event.TreeSelectionEvent;
import javax.swing.event.TreeSelectionListener;
import javax.swing.table.JTableHeader;
import javax.swing.tree.DefaultMutableTreeNode;
import javax.swing.tree.DefaultTreeCellRenderer;
import javax.swing.tree.TreeNode;
import javax.swing.tree.TreePath;
import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
//字体设置 label1.setFont(new Font("宋体",Font.BOLD,16));

public class ViewInitialization {
    public ViewInitialization() throws Exception {
        jf = new JFrame("文件资源管理器");
        jf.setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
        jf.setLocationRelativeTo(null);
        jf.pack();
        jf.setVisible(false);
        surface(1800, 1000, jf);
    }

    private int currentKeyCode;
    private static JFrame jf;
    private JPanel contentPane;
    private JMenuBar menu;
    private JButton button1;
    private JButton button2;
    private JPanel catelog;
    private JPanel commandLine;
    private CmdTextArea cmdTextArea;
    private JPanel view;
    private JPanel right;
    private JPanel bottom;
    private JPanel left;
    private JPopupMenu listPopupMenu;
    private JPopupMenu filePopupMenu;
    private JPopupMenu rootPopupMenu;
    private JTree tree;
    private DefaultMutableTreeNode selectionNode;
    private TreePath movePath;
    private FileUtil fileUtil;
    private JButton buttons[];
    private DefaultMutableTreeNode rootNode;

    public static void t(){
        f.setVisible(true);
    }
    private void initial() throws Exception {
        fileUtil = new FileUtil();
        contentPane = new JPanel();
        ContentPane.setLayout(new BorderLayout());
        menu = new JMenuBar();
        button1 = new JButton("回退");
        button2 = new JButton("前进");
        view  = new JPanel(new GridLayout(32, 8, 15, 10));
        catlog = new JPanel();
        right = new JPanel();
        bottom = new JPanel();
        left = new JPanel();
        cmdTextArea = new CmdTextArea();
    }
    private void surface(int width, int height, JFrame jf){
        initial();
        jf.setContentPane(contentPane);
        setView();
        contentPane.add(right, BorderLayout.EAST);
        right.setPreferredSize(new Dimension(10, 0));

        contentPane.add(bootom, BorderLayout.SOUTH);
        bottom.setPreferredSize(new Dimension(0,10));

        contentPane.add(left, BorderLayout.WEST);
        left.setPreferredSize(new Dimension(10, 0));

        jf.setSize(width, height);
        jf.setLocation(0, 0);
    }
}