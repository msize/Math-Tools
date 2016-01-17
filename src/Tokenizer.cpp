#include "Tokenizer.h"
#include <algorithm>

Tokenizer::Tokenizer(const std::string &expression,
          const std::string &seporators,
          const std::string &singleTokens,
          const std::string &multipleTokens)
    : m_expression(expression),
      m_seporators(seporators),
      m_singleTokens(singleTokens),
      m_multipleTokens(multipleTokens) {
}

std::string Tokenizer::getNextToken() {
  auto pos = m_expression.find_first_not_of(m_seporators, m_pos);
  m_pos = pos + ((std::string::npos == m_singleTokens.find_first_of(m_expression.at(pos))) ? 0 : 1);
  m_pos = (pos == m_pos) ? m_expression.find_first_not_of(m_multipleTokens, pos) : m_pos;
  if (pos == m_pos && !done())
    throw Exception(m_pos);
  return m_expression.substr(pos, m_pos - pos);
}
