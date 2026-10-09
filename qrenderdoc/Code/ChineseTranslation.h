// Local Simplified Chinese UI support. Capture/replay logic is intentionally unchanged.
#pragma once

#include <QFile>
#include <QHash>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTranslator>

class ChineseTranslation final : public QTranslator
{
public:
  explicit ChineseTranslation(QObject *parent = nullptr) : QTranslator(parent)
  {
    QFile file(QStringLiteral(":/translations/zh_CN.json"));
    if(!file.open(QIODevice::ReadOnly))
      return;

    const QJsonObject object = QJsonDocument::fromJson(file.readAll()).object();
    for(auto it = object.constBegin(); it != object.constEnd(); ++it)
      m_Text.insert(it.key(), it.value().toString());
  }

  bool isEmpty() const override { return m_Text.isEmpty(); }

  QString translate(const char *context, const char *sourceText,
                    const char *disambiguation = nullptr, int n = -1) const override
  {
    Q_UNUSED(context);
    Q_UNUSED(disambiguation);
    if(!sourceText)
      return QString();

    const auto it = m_Text.constFind(QString::fromUtf8(sourceText));
    if(it == m_Text.constEnd())
      return QString();

    QString translated = it.value();
    if(n >= 0)
      translated.replace(QStringLiteral("%n"), QString::number(n));
    return translated;
  }

private:
  QHash<QString, QString> m_Text;
};
