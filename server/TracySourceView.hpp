#include <vector>

struct ImFont;

namespace tracy
{

class SourceView
{
    struct Line
    {
        const char* begin;
        const char* end;
    };

public:
    SourceView( ImFont* font );
    ~SourceView();

    void Open( const char* fileName, int line );
    void Render();

private:
    void RenderLine( const Line& line, int lineNum );

    ImFont* m_font;
    const char* m_file;
    char* m_data;
    size_t m_dataSize;
    int m_targetLine;
    int m_selectedLine;

    std::vector<Line> m_lines;
};

}