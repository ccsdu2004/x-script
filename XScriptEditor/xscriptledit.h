#ifndef XSCRIPTEDIT
#define XSCRIPTEDIT
#include <qscopedpointer.h>
#include <qplaintextedit.h>

class XScriptEditPrivate;

class XScriptEdit: public QPlainTextEdit {
    Q_OBJECT
  public:
    typedef enum {
        Background,
        Normal,
        Comment,
        Number,
        String,
        Operator,
        Identifier,
        Keyword,
        BuiltIn,
        Sidebar,
        LineNumber,
        Cursor,
        Marker,
        BracketMatch,
        BracketError,
        FoldIndicator
    } ColorComponent;
  public:
    XScriptEdit(QWidget* parent = nullptr);
    ~XScriptEdit();
  public:
    void setColor(ColorComponent component, const QColor& color);

    bool isBracketsMatchingEnabled() const;
    bool isCodeFoldingEnabled() const;
    bool isLineNumbersVisible() const;
    bool isTextWrapEnabled() const;

    bool isFoldable(int line) const;
    bool isFolded(int line) const;

  public slots:
    void updateSidebar();
    void mark(const QString& str, Qt::CaseSensitivity sens = Qt::CaseInsensitive);
    void setBracketsMatchingEnabled(bool enable);
    void setCodeFoldingEnabled(bool enable);
    void setLineNumbersVisible(bool visible);
    void setTextWrapEnabled(bool enable);

    void fold(int line);
    void unfold(int line);
    void toggleFold(int line);
    void indent();
  protected:
    virtual void resizeEvent(QResizeEvent* e) override;
    virtual void wheelEvent(QWheelEvent* e) override;
    //virtual void contextMenuEvent(QContextMenuEvent *e) override;
  private slots:
    void updateCursor();
    void updateSidebar(const QRect& rect, int d);
  private:
    QScopedPointer<XScriptEditPrivate> d_ptr;
    Q_DECLARE_PRIVATE(XScriptEdit);
    Q_DISABLE_COPY(XScriptEdit);
};

#endif // OFILABS_GLSLEDIT
