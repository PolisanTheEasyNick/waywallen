module;
#include "QExtra/macro_qt.hpp"

#ifdef Q_MOC_RUN
#    include "waywallen/query/renderer_query.moc"
#endif

export module waywallen:query.renderer;
export import :query.query;

namespace waywallen
{

export class RendererListQuery : public Query,
                                 public QueryExtra<control::v1::Response, RendererListQuery> {
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QStringList renderers READ renderers NOTIFY renderersChanged FINAL)
    Q_PROPERTY(QVariantList instances READ instances NOTIFY instancesChanged FINAL)

public:
    RendererListQuery(QObject* parent = nullptr);

    auto renderers() const -> const QStringList&;
    auto instances() const -> const QVariantList&;

    void reload() override;

    Q_SIGNAL void renderersChanged();
    Q_SIGNAL void instancesChanged();

private:
    QStringList  m_renderers;
    QVariantList m_instances;
};

export class RendererPluginListQuery
    : public Query,
      public QueryExtra<control::v1::Response, RendererPluginListQuery> {
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QVariantList renderers READ renderers NOTIFY renderersChanged FINAL)
    Q_PROPERTY(QStringList supportedTypes READ supportedTypes NOTIFY supportedTypesChanged FINAL)
    /// Wallpaper type key -> display label, for the keys in
    /// `supportedTypes` whose renderer declares one. A missing key means
    /// the UI shows the key itself, as it always did.
    Q_PROPERTY(QVariantMap typeLabels READ typeLabels NOTIFY typeLabelsChanged FINAL)

public:
    RendererPluginListQuery(QObject* parent = nullptr);

    auto renderers() const -> const QVariantList&;
    auto supportedTypes() const -> const QStringList&;
    auto typeLabels() const -> const QVariantMap&;

    void reload() override;

    Q_SIGNAL void renderersChanged();
    Q_SIGNAL void supportedTypesChanged();
    Q_SIGNAL void typeLabelsChanged();

private:
    QVariantList m_renderers;
    QStringList  m_supported_types;
    QVariantMap  m_type_labels;
};

export class RendererKillQuery : public Query,
                                 public QueryExtra<control::v1::Response, RendererKillQuery> {
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(
        QString rendererId READ rendererId WRITE setRendererId NOTIFY rendererIdChanged FINAL)

public:
    RendererKillQuery(QObject* parent = nullptr);

    auto rendererId() const -> const QString&;
    void setRendererId(const QString&);

    void reload() override;

    Q_SIGNAL void rendererIdChanged();

private:
    QString m_renderer_id;
};

} // namespace waywallen
