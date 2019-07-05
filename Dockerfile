FROM ruby:2.5.1

# Install Oniguruma
RUN \
  cd /tmp && \
  curl -SL https://github.com/kkos/oniguruma/releases/download/v6.9.2/onig-6.9.2.tar.gz | tar xvz && \
  cd onig-6.9.2 && \
  autoreconf -i && \
  ./configure && \
  make && \
  make install && \
  ldconfig

ENV LANG=C.UTF-8

COPY c-program ./c-program
COPY ruby-c-ext ./ruby-c-ext
COPY run_all_tests.sh run_all_tests.sh

CMD ["bash", "run_all_tests.sh"]
