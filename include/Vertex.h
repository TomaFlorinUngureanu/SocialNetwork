#ifndef SHORELINE_VERTEX_H
#define SHORELINE_VERTEX_H

#include <string>
#include <utility>

class Vertex
{
private:
    std::string m_label;

public:
    /**
     *
     */
    Vertex() = default;

    /**
     *
     * @param label
     */
    explicit Vertex(std::string label): m_label(std::move(label)) {};

    /**
     *
     * @param vertex
     */
    Vertex(const Vertex& vertex);

    /**
     *
     * @param vertex
     */
    Vertex(Vertex&& vertex) noexcept;

    /**
     *
     * @param vertex
     * @return
     */
    Vertex& operator=(const Vertex& vertex);

    /**
     *
     * @param vertex
     * @return
     */
    Vertex& operator=(Vertex&& vertex) noexcept;

    /**
     *
     * @param vertex
     * @return
     */
    bool operator==(const Vertex& vertex) const;

    /**
     *
     * @return
     */
    std::string getLabel();

    /**
     *
     * @param label
     */
    void setLabel(const std::string& label);
};


#endif //SHORELINE_VERTEX_H
