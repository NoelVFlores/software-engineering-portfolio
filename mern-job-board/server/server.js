import express from "express";
import cors from "cors";
import records from "./routes/record.js";
import checkJwt from "./middleware/auth.js"; // ✅ import token validator

const PORT = process.env.PORT || 5050;
const app = express();

app.use(cors());
app.use(express.json());

// Public GET
app.use("/record", (req, res, next) => {
  if (req.method === "GET") {
    return records(req, res, next);
  }
  // ✅ Authenticate for all other /record routes (e.g. POST)
  return checkJwt(req, res, () => records(req, res, next));
});

app.listen(PORT, () => {
  console.log(`Server listening on port ${PORT}`);
});
