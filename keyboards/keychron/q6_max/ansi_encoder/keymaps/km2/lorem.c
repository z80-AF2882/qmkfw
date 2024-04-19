#include QMK_KEYBOARD_H

#define LOREM_ALL 437
#define LOREM_UP_TO_2 18
#define LOREM_UP_TO_3 52
#define LOREM_UP_TO_5 157

static const char *lorem_words[] = {
    "a", "ac", "ad", "an", "at", "cu", "ea", "ei", "et", "eu", "ex", "id", "in", "mi", "ne", "no", "te", "ut", "cum", "dis", "dui", "duo", "eam", "eos", "est", "eum", "hac", "has", "his", "ius", "leo", "mea", "mei", "mel", "mus", "nam", "nec", "non", "per", "pri", "pro", "qui", "quo", "sea", "sed", "sem", "sit", "usu", "vel", "vim", "vis", "vix", "wisi" "agam", "alia", "amet", "ante", "arcu", "cras", "diam", "dico", "duis", "eget", "eius", "elit", "enim", "erat", "eros", "esse", "hinc", "nibh", "nisi", "nisl", "nunc", "odio", "orci", "quam", "quas", "quem", "quis", "quod", "quot", "sale", "suas", "sumo", "tale", "tota", "unum", "urna", "veri", "vero", "adhuc", "aeque", "atqui", "augue", "autem", "brute", "class", "curae", "debet", "dicam", "dicat", "dicit", "dicta", "dolor", "donec", "elitr", "errem", "error", "etiam", "falli", "fames", "felis", "ferri", "fugit", "fusce", "habeo", "harum", "idque", "inani", "ipsum", "iusto", "justo", "lacus", "liber", "lorem", "ludus", "magna", "massa", "mazim", "metus", "minim", "morbi", "movet", "mutat", "natum", "neque", "netus", "nihil", "nobis", "novum", "nulla", "porro", "porta", "posse", "proin", "purus", "reque", "risus", "saepe", "simul", "solet", "solum", "sonet", "velit", "viris", "vitae", "aenean", "affert", "altera", "animal", "aptent", "auctor", "audire", "causae", "cetero", "congue", "consul", "cursus", "decore", "dicant", "dictas", "dictum", "dicunt", "doctus", "dolore", "doming", "eirmod", "graece", "graeci", "graeco", "homero", "ignota", "iisque", "iriure", "latine", "laudem", "lectus", "legere", "libero", "libris", "ligula", "litora", "luctus", "magnis", "mattis", "mauris", "melius", "mollis", "montes", "mucius", "nonumy", "noster", "nostra", "nullam", "option", "oratio", "ornare", "platea", "populo", "possim", "possit", "postea", "primis", "putent", "quidam", "ridens", "rutrum", "sapien", "semper", "sociis", "taciti", "tantas", "tation", "tellus", "tempor", "tempus", "tortor", "turpis", "ubique", "utamur", "utinam", "varius", "veniam", "verear", "vocent", "alienum", "aliquam", "aliquet", "aliquid", "aliquip", "alterum", "aperiri", "blandit", "ceteros", "civibus", "commodo", "commune", "conubia", "cubilia", "dapibus", "delenit", "discere", "docendi", "dolorem", "dolores", "dolorum", "egestas", "epicuri", "equidem", "eripuit", "eruditi", "euismod", "fabulas", "facilis", "feugait", "feugiat", "finibus", "fuisset", "graecis", "gravida", "habemus", "iaculis", "impetus", "integer", "iuvaret", "labores", "lacinia", "laoreet", "legimus", "maiorum", "malorum", "maximus", "meliore", "natoque", "nonumes", "nostrum", "numquam", "omittam", "ornatus", "persius", "posuere", "potenti", "pretium", "prompta", "quaeque", "quisque", "regione", "rhoncus", "sanctus", "saperet", "scripta", "sodales", "tamquam", "tibique", "tritani", "utroque", "veritus", "viderer", "vidisse", "vivamus", "vivendo", "viverra", "vocibus", "volumus", "accumsan", "accusata", "adipisci", "ancillae", "antiopam", "appareat", "appetere", "atomorum", "bibendum", "delectus", "delicata", "deserunt", "detracto", "detraxit", "dictumst", "electram", "eleifend", "epicurei", "fabellas", "facilisi", "fastidii", "faucibus", "habitant", "inceptos", "indoctum", "inimicus", "interdum", "invenire", "invidunt", "lobortis", "luptatum", "maecenas", "mandamus", "menandri", "mentitum", "molestie", "nascetur", "noluisse", "nominavi", "offendit", "omnesque", "oporteat", "percipit", "pericula", "perpetua", "pertinax", "pharetra", "placerat", "platonem", "ponderum", "praesent", "propriae", "pulvinar", "quaestio", "recteque", "sagittis", "senectus", "senserit", "singulis", "sociosqu", "suscipit", "torquent", "ultrices", "vehicula", "verterem", "volutpat", "conceptam", "consequat", "convallis", "convenire", "corrumpit", "curabitur", "dignissim", "efficitur", "elementum", "erroribus", "euripidis", "evertitur", "expetenda", "explicari", "facilisis", "fermentum", "fringilla", "gloriatur", "gubergren", "habitasse", "hendrerit", "himenaeos", "imperdiet", "iudicabit", "malesuada", "maluisset", "mediocrem", "molestiae", "ocurreret", "partiendo", "patrioque", "penatibus", "periculis", "persecuti", "petentium", "phasellus", "porttitor", "postulant", "principes", "prodesset", "qualisque", "repudiare", "ridiculus", "salutatus", "sapientem", "similique", "splendide", "suavitate", "tacimates", "tincidunt", "tractatos", "tristique", "ultricies", "urbanitas", "venenatis", "vulputate"
};

uint16_t lorem_len = 0;
uint16_t lorem_wc = 0;


void send_random_lorem_word(bool last_word) {
    uprintf("LOREM START wc=%d len=%d\n", lorem_wc, lorem_len);
    uint8_t d6;
    d6 = rand() % 6;
    uint16_t limit = LOREM_ALL;
    if ((lorem_len > 25) && (d6 == 0)) {
        limit = LOREM_UP_TO_2;
        lorem_len = 0;
    }
    if ((lorem_len > 25) && (d6 == 1)) {
        limit = LOREM_UP_TO_3;
        lorem_len = 0;
    }
    if ((lorem_len > 40) && (d6 < 2)) {
        limit = LOREM_UP_TO_3;
        lorem_len = 0;
    }
    if ((lorem_len > 40) && (d6 < 4)) {
        limit = LOREM_UP_TO_5;
        lorem_len = 0;
    }
    uint16_t word_index = rand() % limit;
    lorem_len += strlen(lorem_words[word_index]);
    SEND_STRING(lorem_words[word_index]);
    if (last_word) {
        SEND_STRING(".");
        lorem_wc = 0;
        lorem_len = 0;
        return;
    }
    lorem_wc++;
    d6 = rand() % 6;
    if ((lorem_wc > 6) && (d6 < 1)) {
        SEND_STRING(", ");
        lorem_wc = 0;
        return;
    }
    if ((lorem_wc > 7) && (d6 < 2)) {
        SEND_STRING(". ");
        lorem_wc = 0;
        return;
    }
    if ((lorem_wc > 5) && (d6 < 4) && (lorem_len > 40)) {
        SEND_STRING(". ");
        lorem_wc = 0;
        return;
    }
    SEND_STRING(" ");
}
