class Button : public QWidget
{
       Q_OBJECT

       public:
            Button(....);

       protected:
            void mousePressEvent(QMouseEvent*);
            void mouseReleaseEvent(QMouseEvent*);
            void paintEvent(QPaintEvent*);

      private:
             bool state;

      signals:
             void clicked();
             void release();
             void pressed();
};

Button::Button(............)
{
     state = 0;
}

void Button::mousePressEvent(....)
{
         state = 1;
         repaint();
         emit pressed();
}

void Button::mouseReleaseEvent(....)
{
         state = 0;
         repaint();
         emit released();
         emit clicked();
}

void Button::paintEvent(....)
{
         if(state)
                  ...............
         else
                  .............;
}
