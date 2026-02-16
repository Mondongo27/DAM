<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <title>Form data received</title>
  <style>
    body {
      font-family: Arial, sans-serif;
      background-color: #111;
      color: #f4f4f4;
      padding: 2rem;
    }
    h1 {
      color: goldenrod;
    }
    pre {
      background-color: #222;
      border: 1px solid #444;
      padding: 1rem;
      border-radius: 8px;
      overflow-x: auto;
    }
    a {
      color: lightblue;
    }
  </style>
</head>
<body>
  <h1>✅ Form data received successfully!</h1>
  <p>Here is the information you sent:</p>

  <pre>
<?php
  // Muestra todos los datos recibidos por GET o POST
  if (!empty($_GET)) {
      print_r($_GET);
  } elseif (!empty($_POST)) {
      print_r($_POST);
  } else {
      echo "No data received.";
  }
?>
  </pre>

  <p><a href="formulario.html">⬅️ Back to the form</a></p>
</body>
</html>
