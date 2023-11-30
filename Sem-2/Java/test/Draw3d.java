package test;

import javax.swing.*;
import java.awt.*;

public class Draw3d extends JPanel {
    public void paintComponent(Graphics g)
    {
        Graphics2D g2d= (Graphics2D) g;
        int []x ={100,160,180,120};
        int []y={100,100,80,80};
        int []x1={160,160,180,180};
        int []y1={100,160,140,80};
        int []x2={100,160,140,80};
        int []y2={160,160,180,180};
        int n=4;
        g.setColor(Color.red);
        g.fill3DRect(100,100,60,60,true);
        g.setColor(Color.blue);
        g.fillPolygon(x,y,n);
        g.setColor(Color.GREEN);
        g.fillPolygon(x1,y1,n);
        g.setColor(Color.LIGHT_GRAY);
        g.fillPolygon(x2,y2,n);
        g.setColor(Color.BLACK);
        g.drawRect(100,100,60,60);
        g.drawRect(120,80,60,60);
        g.drawLine(100,100,120,80);
        g.drawLine(160,100,180,80);
        g.drawLine(160,160,180,140);
        g.drawLine(100,160,120,140);
    }

    public static void main(String[] args) {
    	Draw3d  m = new Draw3d();
        JFrame  f  =  new JFrame("3D cube drawing");
        f.setSize(500,600);
        f.setVisible(true);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.add(m);
    }
}