FROM epitechcontent/epitest-docker:devel

COPY include/ /app/include/
COPY lib/ /app/lib/
COPY ressources/ /app/ressources/
COPY src/ /app/src/
COPY Makefile /app/

WORKDIR /app/
RUN make re

CMD ["mv", "./my_world", "/app/shared"]