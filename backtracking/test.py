def wrapper(func) {
    try {
        conn = connect()
        func(conn)
    } except () {

    } finally {
        conn.close()
    }
}

def _insert(conn) {
    conn.execute("INSERT INTO table VALUES ()")
}

def _delete(conn) {
    conn.execute("DELETE FROM table WHERE ??")
}

def insert() {
    wrapper(_insert)
}

def delete() {
    wrapper(_delete)
}